<script setup lang="ts">
import type { FormSubmitEvent, AuthFormField } from "@nuxt/ui";
import * as z from "zod";

const error = ref(false);
const authCookie = useCookie("auth", { maxAge: 60 * 60 * 24 * 7 });

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
    password: z
        .string("Password is required")
        .min(5, "Must be at least 5 characters"),
});

function handleLogin(payload: FormSubmitEvent<Schema>) {
    if (payload.data.password === process.env.POPO) {
        authCookie.value = "authenticated";
        navigateTo("/");
    } else {
        error.value = true;
    }
}

type Schema = z.output<typeof schema>;
</script>

<template>
    <div class="flex flex-col items-center justify-center gap-4 p-4">
        <UPageCard class="w-full max-w-md">
            <UAuthForm
                :schema="schema"
                title="Login"
                description="Enter your credentials to access your account."
                icon="i-lucide-user"
                :fields="fields"
                @submit.prevent="handleLogin"
                :submit="{
                    label: 'Submit',
                    color: 'info',
                    variant: 'subtle',
                }"
            />
            <div
                v-if="error"
                class="text-error-600 border-error-600 border text-center rounded-xl py-2"
            >
                Mot de passe incorrect
            </div>
        </UPageCard>
    </div>
</template>
