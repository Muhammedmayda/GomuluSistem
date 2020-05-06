import cv2 

webcam = cv2.VideoCapture(0)
check, frame = webcam.read()
new_image = cv2.cvtColor(frame,cv2.COLOR_BGR2GRAY)
cv2.imwrite(filename='saved_img.jpg', img=new_image)
webcam.release()

   
        
