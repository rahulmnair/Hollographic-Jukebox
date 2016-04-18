import cv2
import numpy as np
import tkinter as tk

img = cv2.imread('a.png',0)
root = tk.Tk()

end_resx = root.winfo_screenwidth()
end_resy = root.winfo_screenheight()

def rotated1(rows, cols):
	M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)
	
def rotated2(rows, cols):
	M = cv2.getRotationMatrix2D((cols/2,rows/2),180,1)
	
def rotated3(rows, cols):
	M = cv2.getRotationMatrix2D((cols/2,rows/2),270,1)

	
	
	
	
def trip_tastic(img, end_resx, end_resy):
	srows, scols, channels = np.shape(img)
	imagex = 768/ 2.125
	scale = imagex/scols
	flipped = cv2.flip(img, flipCode=1)
	source = cv2.resize(flipped,None, fx=scale, fy=scale, interpolation=cv2.INTER_LINEAR)
	rows, cols, channels = np.shape(source)
	first = rotated1(rows, cols)
	second = rotated2(rows, cols)
	third = rotated3(rows, cols)

	background = np.zeros((end_resx, end_resy, 3), np.uint8)
	background[0: rows, rows: (rows + cols)] = source
	background[rows: rows + cols, 0: rows] = first
	background[rows + cols:(rows + cols + rows), (rows):(rows + cols)] = second
	background[rows:rows + cols, (rows + cols):(rows + cols + rows)] = third
	return background
	
trip_tastic(img)
