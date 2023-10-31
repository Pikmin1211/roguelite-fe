
.thumb

@unit
ldr	r7,=#0x2003BFC
ldr	r0,[r7,#0xC]

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

End:
ldr	r1,=#0x8086E54
mov	lr,r1
.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
