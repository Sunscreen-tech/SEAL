// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT license.

// SEALNet
#include "seal/c/decryptor.h"
#include "seal/c/utilities.h"

// SEAL
#include "seal/decryptor.h"

using namespace std;
using namespace seal;
using namespace seal::c;

SEAL_C_FUNC Decryptor_Create(void *context, void *secret_key, void **decryptor)
{
    const SEALContext *ctx = FromVoid<SEALContext>(context);
    IfNullRet(ctx, E_POINTER);
    SecretKey *secretKey = FromVoid<SecretKey>(secret_key);
    IfNullRet(secretKey, E_POINTER);
    IfNullRet(decryptor, E_POINTER);

    try
    {
        Decryptor *decr = new Decryptor(*ctx, *secretKey);
        *decryptor = decr;
        return S_OK;
    }
    catch (const invalid_argument &)
    {
        return E_INVALIDARG;
    }
}

SEAL_C_FUNC Decryptor_Destroy(void *thisptr)
{
    Decryptor *decryptor = FromVoid<Decryptor>(thisptr);
    IfNullRet(decryptor, E_POINTER);

    delete decryptor;
    return S_OK;
}

SEAL_C_FUNC Decryptor_Decrypt(void *thisptr, void *encrypted, void *destination)
{
    Decryptor *decryptor = FromVoid<Decryptor>(thisptr);
    IfNullRet(decryptor, E_POINTER);
    Ciphertext *encryptedptr = FromVoid<Ciphertext>(encrypted);
    IfNullRet(encryptedptr, E_POINTER);
    Plaintext *destinationptr = FromVoid<Plaintext>(destination);
    IfNullRet(destinationptr, E_POINTER);

    try
    {
        decryptor->decrypt(*encryptedptr, *destinationptr);
        return S_OK;
    }
    catch (const invalid_argument &)
    {
        return E_INVALIDARG;
    }
}

SEAL_C_FUNC Decryptor_DecryptAndExtractNoise(void *thisptr, void *encrypted, void *destination, void *noise)
{
    Decryptor *decryptor = FromVoid<Decryptor>(thisptr);
    IfNullRet(decryptor, E_POINTER);
    Ciphertext *encryptedptr = FromVoid<Ciphertext>(encrypted);
    IfNullRet(encryptedptr, E_POINTER);
    Plaintext *destinationptr = FromVoid<Plaintext>(destination);
    IfNullRet(destinationptr, E_POINTER);
    Ciphertext *noiseptr = FromVoid<Ciphertext>(noise);
    IfNullRet(encryptedptr, E_POINTER);

    try
    {
        decryptor->decrypt_and_extract_noise(*encryptedptr, *destinationptr, *noiseptr);
        return S_OK;
    }
    catch (const invalid_argument &)
    {
        return E_INVALIDARG;
    }
}

SEAL_C_FUNC Decryptor_InvariantNoise(void *thisptr, void *encrypted, double *invariant_noise_budget)
{
    Decryptor *decryptor = FromVoid<Decryptor>(thisptr);
    IfNullRet(decryptor, E_POINTER);
    Ciphertext *encryptedptr = FromVoid<Ciphertext>(encrypted);
    IfNullRet(encryptedptr, E_POINTER);
    IfNullRet(invariant_noise_budget, E_POINTER);

    try
    {
        *invariant_noise_budget = decryptor->invariant_noise(*encryptedptr);
        return S_OK;
    }
    catch (const invalid_argument &)
    {
        return E_INVALIDARG;
    }
}


SEAL_C_FUNC Decryptor_InvariantNoiseBudget(void *thisptr, void *encrypted, int *invariant_noise_budget)
{
    Decryptor *decryptor = FromVoid<Decryptor>(thisptr);
    IfNullRet(decryptor, E_POINTER);
    Ciphertext *encryptedptr = FromVoid<Ciphertext>(encrypted);
    IfNullRet(encryptedptr, E_POINTER);
    IfNullRet(invariant_noise_budget, E_POINTER);

    try
    {
        *invariant_noise_budget = decryptor->invariant_noise_budget(*encryptedptr);
        return S_OK;
    }
    catch (const invalid_argument &)
    {
        return E_INVALIDARG;
    }
}
