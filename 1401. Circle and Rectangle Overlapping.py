class Solution(object):
    def checkOverlap(self, radius, xCenter, yCenter, x1, y1, x2, y2):
        nearest_x = max(x1, min(x2, xCenter))
        nearest_y = max(y1, min(y2, yCenter))


        dist_x = nearest_x - xCenter
        dist_y = nearest_y - yCenter
        
        return dist_x**2 + dist_y**2 <= radius**2
        
