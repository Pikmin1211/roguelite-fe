
.thumb

push	{r5}
mov	r5,r2
ldr	r0,[r5,#0x2C]

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

mov	r2,r5
pop	{r5}
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800

ldr	r3,=#0x809B9FB
bx	r3

.align
.ltorg
GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
