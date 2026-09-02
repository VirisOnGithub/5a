<script setup lang="ts">
import type { FormSubmitEvent, AuthFormField } from "@nuxt/ui";
import * as z from "zod";

const error = ref(false);

definePageMeta({
    layout: "login",
});

const fields: AuthFormField[] = [
    {
        name: "password",
        label: "Password",
        type: "password",
        placeholder: "Enter your password",
        required: true,
    },
];

const schema = z.object({
    password: z.string().min(5, "Must be at least 5 characters"),
});

type Schema = z.output<typeof schema>;

async function handleLogin(payload: FormSubmitEvent<Schema>) {
    error.value = false;

    try {
        await $fetch("/api/login", {
            method: "POST",
            body: { password: payload.data.password },
        });

        navigateTo("/");
    } catch (err) {
        error.value = true;
    }
}
</script>

<template>
    <div class="flex flex-col items-center justify-center gap-4 p-4">
        <ClientOnly>
            <UPageCard class="w-full max-w-md">
                <UAuthForm
                    :schema="schema"
                    title="Login"
                    description="Enter your credentials to access your account."
                    icon="i-lucide-user"
                    :fields="fields"
                    @submit="handleLogin"
                    :submit="{
                        label: 'Submit',
                        color: 'info',
                        variant: 'subtle',
                    }"
                />
                <div
                    v-if="error"
                    class="text-error-600 border-error-600 border text-center rounded-xl py-2 mt-4"
                >
                    Mot de passe incorrect
                </div>
            </UPageCard>
        </ClientOnly>
    </div>
</template>
