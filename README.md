# Steganography-GANS
## Abstract
The Internet of Things (IoT) describes the network of physical objects or
things that are embedded with sensors, software, and other technologies to connect and exchange data with other devices and systems
over the Internet. Although several IoT devices are openly accessible to all in
the network, it is extremely vital to be aware of the security risks and threats of
cyber-attacks; therefore, it should be secured. In Cryptography, plain text is
converted to encrypted text before it is sent, and it is converted to plain text
after communication on the other side. Steganography is a method of hiding
secret data, by embedding it into an audio, video, image, or text file. One
technique is to hide data in bits that represent the same color pixels repeated
in a row in an image file. By applying the encrypted data to this redundant data
in some inconspicuous way, the result will be an image file that appears
identical to the original image but that has "noise" patterns of regular,
unencrypted data. In this project proposes to encrypt the IoT network's data
by hiding the message inside an image file using the image data hiding technique.
We are going to incorporate the usage of convolutional neural networks in
traditional image data-hiding methods to drastically increase the payload that
can be transmitted through an image. Different convolutional parameters will
be analyzed to achieve the highest payload. Encryption and decryption of the
data will be performed using the newly developed deep learning algorithm.
Thus, in this project, the convolutional networks will be trained in such a way
to increase the payload of the data to be encrypted as well as safely decrypted
to view the original message.

## Installation 

!pip install imageio>=2.4.1,<2.5.0

!pip install reedsolo==0.3

!pip install scipy>=1.1.0,<1.2.0

!pip install tqdm>=4.28.1

!pip install numpy>=1.15.4<1.16.0

!pip install Pillow>=5.0.0,<7.0.0

!pip install torch==1.4.0

!pip install torchvision==0.2.1

## Run this file

python steg_final.py
