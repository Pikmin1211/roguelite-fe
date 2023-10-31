.equ SkillTester, IdentityProblemsNames+4
.equ IdentityProblemsID, SkillTester+4
.equ IdentityRamByte, IdentityProblemsID+4
.thumb

mov	r6,r0
mov	r0,r5

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800
mov	r1,r0
mov	r0,#0x38
ldr	r3,=#0x8003F90
mov	lr,r3
.short	0xF800
mov	r6,r0

mov	r0,r5

ldr	r3,GetNameTextIdForExternUnit
mov	r14,r3
.short	0xF800
ldr	r3,=#0x800A240
mov	lr,r3
.short	0xF800

End:
ldr	r3,=#0x809A987
bx	r3

.align
.ltorg
GetNameTextIdForExternUnit:
@POIN GetNameTextIdForExternUnit

