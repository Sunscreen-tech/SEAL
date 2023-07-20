#pragma once

#include "seal/c/defines.h"
#include <stdint.h>

SEAL_C_FUNC StaticPolynomialArray_Create(void *memoryPoolHandle, void **poly_array);

SEAL_C_FUNC StaticPolynomialArray_CreateFromCiphertext(void *memoryPoolHandle, void *context, void *ciphertext, void **poly_array);

SEAL_C_FUNC StaticPolynomialArray_CreateFromPublicKey(void *memoryPoolHandle, void *context, void *public_key, void **poly_array);

SEAL_C_FUNC StaticPolynomialArray_Destroy(void *thisptr);

SEAL_C_FUNC StaticPolynomialArray_IsReserved(void *thisptr, bool *is_reserved);

SEAL_C_FUNC StaticPolynomialArray_IsRns(void *thisptr, bool *is_rns);

SEAL_C_FUNC StaticPolynomialArray_IsMultiprecision(void *thisptr, bool *is_multiprecision);

// SEAL_C_FUNC StaticPolynomialArray_InsertPolynomial(void *thisptr, uint64_t poly_index, uint64_t *array);

SEAL_C_FUNC StaticPolynomialArray_ToRns(void *thisptr);

SEAL_C_FUNC StaticPolynomialArray_ToMultiprecision(void *thisptr);

SEAL_C_FUNC StaticPolynomialArray_GetPolynomial(void *thisptr, uint64_t poly_index, uint64_t *data);

SEAL_C_FUNC StaticPolynomialArray_ExportSize(void *thisptr, uint64_t *size);

SEAL_C_FUNC StaticPolynomialArray_PerformExport(void *thisptr, uint64_t *data);

SEAL_C_FUNC StaticPolynomialArray_PolySize(void *thisptr, uint64_t *size);

SEAL_C_FUNC StaticPolynomialArray_PolyModulusDegree(void *thisptr, uint64_t *size);

SEAL_C_FUNC StaticPolynomialArray_CoeffModulusSize(void *thisptr, uint64_t *size);