
.thumb

push	{r5}
mov	r5,r1
ldr	r0,[r5,#0x2C]

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

pop	{r1}
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800
ldr	r3,=#0x802D357
bx	r3

.align
.ltorg
GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
