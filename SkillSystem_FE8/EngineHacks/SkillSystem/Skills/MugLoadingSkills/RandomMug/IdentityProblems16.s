
.thumb

push	{r5}
mov	r5,r1
ldr	r0,[r5,#0x30]

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

End:
mov	r1,r5
pop	{r5}
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800
mov	r7,r0
ldr	r3,=#0x809BA2F
bx	r3

.align
.ltorg
GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
