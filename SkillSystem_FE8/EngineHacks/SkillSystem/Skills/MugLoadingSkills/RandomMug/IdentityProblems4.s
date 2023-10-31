
.thumb

mov	r0,r5

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

End:
ldr	r2,=#0x800A240
mov	lr,r2
.short	0xF800
mov	r1,#0x1F
ldr	r2,=#0x809A5FA
mov	lr,r2
.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
