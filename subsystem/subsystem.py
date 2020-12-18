import serial
arduino = serial.Serial('/dev/ttyUSB0', 115200, timeout=.1)





class SubSystem:
    def update_accuator(self,inputs):
        arduino.write(inputs)
    def read_state(self):
        arduino.write(b'0')
        return

if __name__ =='__main__':
    a=SubSystem()
    a.read_state()
