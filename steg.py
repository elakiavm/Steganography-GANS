import paho.mqtt.client as mqtt
import numpy as np
import pickle
import warnings
warnings.filterwarnings("ignore")
data1=None
def on_message(client, userdata, message):
    data1 = []
    receivedstring = str(message.payload.decode("utf-8"))
    data1=receivedstring.split(",")
    print("Input Data:",float(data1[0]))


broker_address="broker.hivemq.com"
client = mqtt.Client("PSP8266Client")
client.connect(broker_address)
client.on_message=on_message
client.subscribe("temp_123")
while True:
    client.loop()