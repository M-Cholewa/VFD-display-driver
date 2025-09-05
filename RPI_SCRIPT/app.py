import spidev
import time
import struct
import mapping

# This app sends all printable ASCII characters (from space to ~) one by one to the SPI device.
# After sending each character, it waits for the user to press Enter before sending the next one.
# It was made for VFD display driver testing.

def run(msg):
    spi = spidev.SpiDev()
    spi.open(0, 0)

    spi.max_speed_hz = 32000000
    data_to_send = [0x00] * 32
    data_to_send_cp = []
    msg = msg.ljust(8, ' ')
    msg = msg[::-1]

    for ch in range(len(msg)):
        num = mapping.itms[ord(msg[ch])]
        numBytes = struct.pack('<I', num)
        data_to_send[ch*4:(ch*4)+4] = list(numBytes)
        data_to_send_cp += list(numBytes)
        
        
    data_received = spi.xfer2(data_to_send)

    print("Data sent:", [hex(b) for b in data_to_send_cp])
    print("Data received:", [hex(b) for b in data_received])

    spi.close()
    
    
print("Character sent: HELLO")
run("HELLO123")
input("Press Enter to continue...")

for asciiVal in range(32, 127):
    print("Character sent:", chr(asciiVal))
    run(chr(asciiVal))
    input("Press Enter to continue...")
    