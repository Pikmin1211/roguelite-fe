
.thumb

@unit
mov r0, r1

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800

End:
ldr	r2,=#0x800A240
mov	lr,r2
.short	0xF800
mov	r6,r0
mov	r0,#0x38
ldr	r1,=#0x808C600
mov	lr,r1

.short	0xF800
.align
.ltorg

GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit
