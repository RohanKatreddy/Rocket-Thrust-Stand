import serial
import time

f = open("myfile.txt", "w")

def readserial(comport, baudrate, timestamp=False):

    ser = serial.Serial(comport, baudrate, timeout=0.1)         # 1/timeout is the frequency at which the port is read
    input()
    ser.write(1)
    while True:

        data = ser.readline().decode().strip()

        if data and timestamp:
            timestamp = time.strftime('%H:%M:%S')
            f.write(f'{timestamp}, {data}\n')
            print(f'{timestamp}, {data}\n')
        elif data:
            f.write(data)


if __name__ == '__main__':

    readserial('COM9', 9600, True)