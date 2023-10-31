
.thumb

push	{r4}
mov	r4,r0

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

ldr	r4,=#0x800A240
mov	lr,r4
.short	0xF800
mov	r6,r0
mov	r5,r0
ldr	r4,=#0x8052046
mov	lr,r4
pop	{r4}
ldr	r4,=#0x2017678
.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
