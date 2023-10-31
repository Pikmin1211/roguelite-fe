
.thumb

mov	r0,r5

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800

End:
mov	r1,r0
mov	r0,r4
ldr	r3,=#0x809A1E7
bx	r3

.align
.ltorg
GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
