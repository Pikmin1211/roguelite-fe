
.thumb

mov	r0,r6

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800

End:
mov	r4,r0
mov	r0,#0x28
ldr	r2,=#0x8099557
bx	r2

.align
.ltorg
GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
