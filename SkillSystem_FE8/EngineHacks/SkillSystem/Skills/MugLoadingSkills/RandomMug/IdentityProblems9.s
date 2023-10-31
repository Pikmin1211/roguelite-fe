
.thumb
ldr	r0,[r0]
ldr	r0,[r0]
push	{r4}
mov	r4,r0

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

pop	{r4}
ldr	r3,=#0x80923B1
bx	r3
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
