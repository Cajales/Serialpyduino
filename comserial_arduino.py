# -*- coding: utf-8 -*-
"""
Created on Mon Nov  6 21:36:40 2023

@author: 17983999
"""

import serial
import time

class ComunicacionSerial:
    def __init__(self, puerto, baudrate):
        self.arduino = serial.Serial(port=puerto, baudrate=baudrate, timeout=1)
        self.arduino.flush()
        self.arduino_received_zero = True

    def enviar_mensaje(self, mensaje):
        self.arduino.write(mensaje.encode())
        time.sleep(0.1)  # Añade una pequeña pausa para evitar problemas de lectura/escritura simultánea

    def escuchar_mensajes(self):
        while True:
            #print("estoy escuchando")
            if self.arduino.in_waiting >= 0:
                mensaje = self.arduino.readline().decode().strip()
                
                

                if mensaje == "0":
                    self.arduino_received_zero = True
                    break
                else:
                    print("Arduino dice:", mensaje)
                    

    def iniciar_conversacion(self):
        while True:
            #print("estoy hablando")
            if self.arduino_received_zero:
                mensaje = input("Python: ")
                self.enviar_mensaje(mensaje)

                if mensaje == "0" or mensaje =="Hola Arduino, ¿como estás?" or mensaje =="bien":
                    self.arduino_received_zero = False
                    self.escuchar_mensajes()

if __name__ == "__main__":
    puerto_arduino = 'COM3'  # Reemplaza 'COMX' con el puerto COM de tu Arduino
    baudrate = 9600  # Ajusta la velocidad de baudios a la configuración de tu Arduino

    comunicacion = ComunicacionSerial(puerto_arduino, baudrate)
    comunicacion.iniciar_conversacion()
