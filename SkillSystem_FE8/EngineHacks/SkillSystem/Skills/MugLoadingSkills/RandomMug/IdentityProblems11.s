
.thumb

mov	r0,r6

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

End:
ldr	r2,=#0x800A240
mov	lr,r2
.short	0xF800
mov	r4,r0
ldr	r3,=#0x808E24A
mov	lr,r3
.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
