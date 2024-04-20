#! /usr/bin/env python3

from PIL import Image

size = 200

# Open an image file
img = Image.open('image.jpg')

ratio = img.width / img.height
w = int(size * ratio)
h = size
img = img.resize((w, h))

# Convert the image data to a list of tuples
pixels = list(img.getdata())

# with open('image.csv', 'w') as f:
#     for row in range(img.height):
#         for sub in range(3):
#             f.write(",".join([ str(pixels[row * img.width + col][sub]) for col in range(img.width) ]) + "\n")

with open('image.csv', 'w') as f:
    for row in range(h):
        f.write(",".join([ str(int((pixels[row * w + col][0] + pixels[row * w + col][1] + pixels[row * w + col][2]) / 3)) for col in range(w) ]) + "\n")
