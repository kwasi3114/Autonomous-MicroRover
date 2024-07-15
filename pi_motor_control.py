import pyfirmata
import time

ena_pin = 5
enb_pin = 6
in1_pin = 7
in2_pin = 8
in3_pin = 9
in4_pin = 11

board = pyfirmata.Arduino("/dev/ttyACM0")

def forward(carSpeed):
    board.analog[ena_pin].write(carSpeed)
    board.analog[enb_pin].write(carSpeed)
    board.digital[in1_pin].write(1)
    board.digital[in2_pin].write(0)
    board.digital[in3_pin].write(0)
    board.digital[in4_pin].write(1)
    
def backward(carSpeed):
    board.analog[ena_pin].write(carSpeed)
    board.analog[enb_pin].write(carSpeed)
    board.digital[in1_pin].write(0)
    board.digital[in2_pin].write(1)
    board.digital[in3_pin].write(1)
    board.digital[in4_pin].write(0)
    
while True:
    forward(41.62) #41.62 == 2 cm/s for our vehicle
    time.sleep(0.01)
    backward(41.62)
    time.sleep(0.01)
    