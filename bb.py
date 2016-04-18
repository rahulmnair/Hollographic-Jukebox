import cv2
import numpy as np
img = cv2.imread('a.png',0)
srows, scols = img.shape
imagex = 768/ 2.125
scale = imagex/scols
flipped = cv2.flip(img, flipCode=1)
source = cv2.resize(flipped,None, fx=scale, fy=scale, interpolation=cv2.INTER_LINEAR)
background = np.zeros((200, 1024), np.uint8)

rows, cols = np.shape(source)
M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
M2 = cv2.getRotationMatrix2D((cols/2,rows/2),180,1)
M3 = cv2.getRotationMatrix2D((cols/2,rows/2),270,1)
dst2 = cv2.warpAffine(source,M2,(cols,rows))
background[0: rows, rows: (rows + cols)] = source
background[rows: rows + cols, 0: rows] = M2
cv2.imshow('img',background)

cv2.waitKey(0)
cv2.destroyAllWindows()
