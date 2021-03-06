/* dhparam.c: initial DH parameters for stunnel */
#include "common.h"
#ifndef OPENSSL_NO_DH
#define DN_new DH_new
DH *get_dh2048(void)
{
    static unsigned char dhp_2048[] = {
        0xCE, 0xE7, 0xB6, 0xFB, 0x7B, 0xBB, 0x2E, 0x6D, 0xC6, 0x39,
        0xB2, 0x5A, 0x97, 0x20, 0x02, 0x9C, 0x61, 0x57, 0x5C, 0xB7,
        0x1D, 0x01, 0xF9, 0xD9, 0xC2, 0xFA, 0x1E, 0xB4, 0x80, 0x90,
        0x1E, 0xA0, 0x94, 0x9F, 0x4A, 0x31, 0x69, 0x24, 0xDC, 0xE4,
        0xC3, 0x7E, 0x7D, 0xD9, 0xFE, 0xF1, 0x46, 0xD9, 0x1B, 0x9A,
        0x01, 0x02, 0xCA, 0xF0, 0xAD, 0x1B, 0xF0, 0x63, 0x6E, 0xC2,
        0x68, 0x45, 0xD6, 0x76, 0x16, 0x50, 0x91, 0xE2, 0x1A, 0x54,
        0xEC, 0xDD, 0x62, 0x31, 0x8F, 0xCF, 0x25, 0x74, 0x90, 0xB3,
        0x26, 0xED, 0x38, 0xCC, 0xB8, 0x40, 0x2F, 0x0A, 0x59, 0xEF,
        0x0F, 0xAC, 0x36, 0x77, 0x57, 0xE7, 0x9C, 0x12, 0x79, 0x8A,
        0xEA, 0x64, 0xA1, 0xFC, 0x1F, 0xB5, 0xCE, 0x42, 0x32, 0x36,
        0x55, 0xDF, 0x2E, 0xAD, 0xBA, 0x85, 0x91, 0xD7, 0x68, 0x26,
        0xD5, 0x67, 0x7D, 0x8F, 0xAF, 0x5B, 0xEB, 0xE9, 0x72, 0xB8,
        0xEB, 0x1C, 0xEA, 0x90, 0xA5, 0xE2, 0x2A, 0xFC, 0x26, 0xAD,
        0xB9, 0xF2, 0xE1, 0xF7, 0xDD, 0x99, 0x68, 0x51, 0x25, 0x95,
        0xBF, 0xAB, 0x5C, 0x6C, 0x9D, 0x90, 0x41, 0x69, 0xE3, 0x49,
        0xB4, 0xE9, 0xC2, 0xAF, 0x1B, 0xA0, 0x0A, 0x67, 0x37, 0x77,
        0x9C, 0x01, 0xF5, 0xCF, 0x4A, 0x5A, 0xDF, 0xFC, 0x0F, 0x59,
        0xD0, 0x2F, 0xEC, 0x9C, 0x71, 0xEA, 0x46, 0xBC, 0x16, 0x50,
        0xD6, 0xF4, 0x1C, 0x95, 0x98, 0xD7, 0xD5, 0xE8, 0xE6, 0x53,
        0x9E, 0xCF, 0x77, 0xAA, 0x39, 0xB8, 0xE9, 0x41, 0x94, 0x9B,
        0xDD, 0xE1, 0x7D, 0x82, 0xC0, 0x9C, 0x0D, 0xBD, 0xF4, 0x79,
        0x7B, 0x30, 0xCF, 0xFD, 0x3A, 0x0C, 0xBA, 0x9E, 0x23, 0x79,
        0x3D, 0xCB, 0x6C, 0xCC, 0x2A, 0xEC, 0x17, 0x76, 0x09, 0x7A,
        0xC6, 0x2F, 0x70, 0xFF, 0x2C, 0x8C, 0x44, 0xCD, 0x19, 0x45,
        0x8B, 0xE8, 0xAC, 0x70, 0x04, 0xF3
    };
    static unsigned char dhg_2048[] = {
        0x02
    };
    DH *dh = DH_new();
    BIGNUM *p, *g;

    if (dh == NULL)
        return NULL;
    p = BN_bin2bn(dhp_2048, sizeof(dhp_2048), NULL);
    g = BN_bin2bn(dhg_2048, sizeof(dhg_2048), NULL);
    if (p == NULL || g == NULL
            || !DH_set0_pqg(dh, p, NULL, g)) {
        DH_free(dh);
        BN_free(p);
        BN_free(g);
        return NULL;
    }
    return dh;
}
#endif /* OPENSSL_NO_DH */
/* built for stunnel 5.59 */
