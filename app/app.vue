<script setup>
useHead({
    title: "Cours 5A",
    link: [{ rel: "icon", href: "/favicon.ico" }],
});
const { isLoading } = useLoadingIndicator();
</script>

<template>
    <div>
        <Transition name="fade">
            <div v-if="isLoading" class="loading-overlay">
                <div class="spinner"></div>
            </div>
        </Transition>

        <NuxtLayout>
            <NuxtPage />
        </NuxtLayout>
    </div>
</template>

<style scoped>
.loading-overlay {
    position: fixed;
    inset: 0;
    background: rgba(0, 0, 0, 0.5);
    display: flex;
    align-items: center;
    justify-content: center;
    z-index: 9999;
}

.spinner {
    width: 40px;
    height: 40px;
    border: 4px solid #f3f3f3;
    border-top: 4px solid #3b82f6;
    border-radius: 50%;
    animation: spin 1s linear infinite;
}

@keyframes spin {
    0% {
        transform: rotate(0deg);
    }
    100% {
        transform: rotate(360deg);
    }
}

.fade-enter-active,
.fade-leave-active {
    transition: opacity 0.2s;
}
.fade-enter-from,
.fade-leave-to {
    opacity: 0;
}
</style>
