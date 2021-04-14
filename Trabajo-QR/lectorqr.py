import cv2
import sys

filename = sys.argv[1]
img = cv2.imread(filename)
detector = cv2.QRCodeDetector()

data, bbox, straight_qrcode = detector.detectAndDecode(img)

if bbox is not None:
    print(f"Datos del código QR:\n{data}")