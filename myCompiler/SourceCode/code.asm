.code
	mov ax,@data
	mov ds,ax
	mov es,ax
	lea dx,printstr2
	call print
	call newline
	call exittodos
	int 3h

