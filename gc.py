import sys

def main():
    filename = sys.argv[1]
    BUF_SIZE = 1024

    try:
        with open(filename, 'rb') as f:
    
            while True:
                buf = f.read(BUF_SIZE)
    
                if len(buf) == 0:
                    break
    
                sys.stdout.buffer.write(buf)
    
    except FileNotFoundError:
        sys.stderr.write(f"File {filename} not found!")


if __name__ == '__main__':
    
    main()