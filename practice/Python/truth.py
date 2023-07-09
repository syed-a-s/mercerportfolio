# truth tables

def truth (p, q, r) : 
	
	result = (not p or r) and (not q or r) 	
	return result 


for p in [True, False] :
	for q in [True, False] : 
		for r in [True, False] : 
			print (p, q, r, truth(p, q, r))  
