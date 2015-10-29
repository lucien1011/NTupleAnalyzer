
import math

def binoError(selected,allEvent):
	return math.sqrt(selected*(1-selected/allEvent))/allEvent
