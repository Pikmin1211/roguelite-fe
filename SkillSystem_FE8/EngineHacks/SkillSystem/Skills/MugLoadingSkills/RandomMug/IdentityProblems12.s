
.thumb

push	{r5,r6}
mov	r6,r0
mov	r5,r1
mov	r0,r5

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

mov	r1,r5
pop	{r5,r6}
ldr	r2,=#0x800A240
mov	lr,r2
.short	0xF800
mov	r1,r0
ldr	r3,=#0x803498E
mov	lr,r3
.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
