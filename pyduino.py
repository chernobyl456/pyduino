import serial
from PySimpleGUI import PySimpleGUI as sg

# serial config
port = 'COM3'
speed = 9600

ser = serial.Serial(port, speed)


# funções
def LED_1_f():
    ser.write(b'A')


def LED_2_f():
    ser.write(b'B')


def LED_3_f():
    ser.write(b'C')


# layout
sg.theme('DarkBlue2')
layout = [
    [sg.Button('LED_1')],
    [sg.Button('LED_2')],
    [sg.Button('LED_3')]
]

# janela
janela = sg.Window('pyduino', layout)

# leitura de eventos
while True:
    event, valores = janela.read()
    if event == sg.WIN_CLOSED:
        break
    if event == 'LED_1':
        LED_1_f()
    if event == 'LED_2':
        LED_2_f()
    if event == 'LED_3':
        LED_3_f()
