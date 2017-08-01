.section ".sanctum_payload","a",@progbits
.align 3

.globl _sanctum_payload_start, _sanctum_payload_end
_sanctum_payload_start:
.incbin SANCTUM_BOOTLOADER_PAYLOAD
_sanctum_payload_end:
