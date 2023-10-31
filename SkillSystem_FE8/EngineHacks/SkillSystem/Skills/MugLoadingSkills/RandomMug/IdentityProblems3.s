
.thumb

mov	r8,r0
mov	r6,r1
mov	r0,r2

ldr	r2,GetNameTextIdForExternUnit
mov	r14,r2
.short	0xF800

End:
ldr	r1,=#0x80365F4
mov	lr,r1
.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
