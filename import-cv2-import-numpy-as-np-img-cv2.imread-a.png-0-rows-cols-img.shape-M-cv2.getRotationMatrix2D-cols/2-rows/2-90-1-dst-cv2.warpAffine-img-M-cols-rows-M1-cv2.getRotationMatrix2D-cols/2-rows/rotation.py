import cv2
import numpy as np
img = cv2.imread('a.png',0)
rows,cols = img.shape
M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
dst = cv2.warpAffine(img,M,(cols,rows))
M1 = cv2.getRotationMatrix2D((cols/2,rows/2),180,1)
dst2 = cv2.warpAffine(img,M1,(cols,rows))

cv2.imshow('img',dst)
cv2.waitKey(0)
cv2.destroyAllWindows()
