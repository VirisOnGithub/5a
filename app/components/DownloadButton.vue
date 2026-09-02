<template>
    <UButton
        :loading="status === 'loading'"
        :icon="currentIcon"
        :color="currentColor"
        :variant="status === 'success' ? 'soft' : 'solid'"
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

// États possibles : 'idle', 'loading', 'success', 'error'
const status = ref("idle");

// Gestion dynamique des icônes selon l'état
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

// Gestion dynamique des couleurs de Nuxt UI selon l'état
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

// Texte affiché à l'intérieur du bouton
const buttonText = computed(() => {
    switch (status.value) {
        case "loading":
            return `Téléchargement de ${props.filename}...`;
        case "success":
            return `${props.filename} téléchargé !`;
        case "error":
            return `Échec du téléchargement`;
        default:
            return `Télécharger ${props.filename}`;
    }
});

// Logique de téléchargement
const handleDownload = async () => {
    if (status.value === "loading") return;

    status.value = "loading";

    try {
        const response = await fetch(props.url);
        if (!response.ok)
            throw new Error("Erreur réseau lors du téléchargement");

        // Convertir la réponse en Blob pour forcer le téléchargement côté client
        const blob = await response.blob();
        const downloadUrl = window.URL.createObjectURL(blob);

        // Créer un lien temporaire invisible pour déclencher le téléchargement
        const link = document.createElement("a");
        link.href = downloadUrl;
        link.download = props.filename;
        document.body.appendChild(link);
        link.click();

        // Nettoyage
        link.remove();
        window.URL.revokeObjectURL(downloadUrl);

        status.value = "success";
    } catch (error) {
        console.error("Erreur :", error);
        status.value = "error";
    } finally {
        // Réinitialiser le bouton après 3 secondes (qu'il soit en succès ou en erreur)
        setTimeout(() => {
            status.value = "idle";
        }, 3000);
    }
};
</script>
