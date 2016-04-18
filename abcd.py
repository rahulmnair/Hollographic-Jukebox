import cv2
import numpy as np
background = np.zeros((342, 298,2), np.uint8)
img = cv2.imread('a.png',0)
rows,cols = img.shape
background[0: rows, rows: (rows + cols),] = img

cv2.imshow('img',background)
cv2.waitKey(0)
cv2.destroyAllWindows()
