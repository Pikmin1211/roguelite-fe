
.thumb

push	{r4}
mov	r4,r0

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

pop	{r4}
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800
mov	r1,#0
str	r1,[sp]
ldr	r3,=#0x809ECDB
bx	r3
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
