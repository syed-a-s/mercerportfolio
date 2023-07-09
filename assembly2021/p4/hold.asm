; First fib
mov DWORD[temp], previousNum
mov ax, sum
add ax, [previousNum]
mov DWORD[previousNum], temp
mov DWORD[ebx], sum
add ebx, 4

; Second fib
mov DWORD[temp], previousNum
mov ax, sum
add ax, [previousNum]
mov DWORD[previousNum], temp
mov DWORD[ebx], sum
add ebx, 4

; Third fib
mov DWORD[temp], previousNum
mov ax, sum
add ax, [previousNum]
mov DWORD[previousNum], temp
mov DWORD[ebx], sum
add ebx, 4

; Fourth fib
mov DWORD[temp], previousNum
mov ax, sum
add ax, [previousNum]
mov DWORD[previousNum], temp
mov DWORD[ebx], sum
add ebx, 4


mov cx, 16
mov ebx, Fibs
top:
	add cx, 1

	; adding sum and previous num
	mov DWORD[temp], previousNum
	mov ax, sum		; adding sum and previousNum starts here
	add ax, [previousNum]		
	mov DWORD[previousNum], temp 	; setting previousNum
	; storing
	mov DWORD[ebx], sum
	add ebx, 4

	cmp cx, 16	
	jng top

