<template>
    <UButton
        :loading="status === 'loading'"
        :icon="currentIcon"
        :disabled="status === 'loading' || status === 'success'"
        @click="handleDownload"
        class="transition-all duration-300 cursor-pointer border dark:border-white dark:text-white dark:hover:bg-white dark:hover:text-black border-black text-black hover:bg-black hover:text-white"
    >
        {{ buttonText }}
    </UButton>
</template>

<script setup>
import { ref, computed } from "vue";

const props = defineProps({
    url: {
        type: String,
        required: true,
        description: "L'URL du fichier à télécharger",
    },
    filename: {
        type: String,
        required: true,
        description:
            "Le nom du fichier (affiché dans le bouton et utilisé pour la sauvegarde)",
    },
});

const status = ref("idle");

const currentIcon = computed(() => {
    switch (status.value) {
        case "success":
            return "i-heroicons-check-circle";
        case "error":
            return "i-heroicons-exclamation-triangle";
        default:
            return "i-heroicons-arrow-down-tray";
    }
});

const currentColor = computed(() => {
    switch (status.value) {
        case "success":
            return "green";
        case "error":
            return "red";
        default:
            return "primary";
    }
});

const buttonText = computed(() => {
    return props.filename;
});

const handleDownload = async () => {
    if (status.value === "loading") return;

    status.value = "loading";

    try {
        const response = await fetch(props.url);
        if (!response.ok)
            throw new Error("Erreur réseau lors du téléchargement");

        const blob = await response.blob();
        const downloadUrl = window.URL.createObjectURL(blob);

        const link = document.createElement("a");
        link.href = downloadUrl;
        link.download = props.filename;
        document.body.appendChild(link);
        link.click();

        link.remove();
        window.URL.revokeObjectURL(downloadUrl);

        status.value = "success";
    } catch (error) {
        console.error("Erreur :", error);
        status.value = "error";
    } finally {
        setTimeout(() => {
            status.value = "idle";
        }, 3000);
    }
};
</script>
