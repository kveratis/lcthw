type* ptr			a pointer of type named ptr
*ptr				the value of whatever ptr is pointed at
*(ptr+i)			the value of whatever ptr is pointed at plus i
&thing				The address of thing
type* ptr = &thing	a pointer of type named ptr set to the address of thing
ptr++				increment where ptr points

## Pointers are Not Arrays

Never think that pointers and arrays are the same thing.  They are not the
same thing even though C lets you work with them in many of the same ways.
Ex: sizeof(cur_age) will dive you the size of the pointer, not the size of
what it points at.  If you want the size of the full array, you have to use
the array name, age.

