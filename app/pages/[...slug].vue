<script setup lang="ts">
const route = useRoute();
const { data: post } = await useAsyncData(route.path, () =>
    queryCollection("class").path(route.path).first(),
);

useSeoMeta({
    title: () => post.value?.title,
    description: () => post.value?.description,
    ...post.value?.seo,
});
</script>

<template>
    <UButton
        to="/"
        class="p-2 m-2 border border-white bg-transparent text-white"
    >
        &larr; Retour à l'accueil
    </UButton>
    <div class="py-4"></div>
    <ContentRenderer v-if="post" :value="post" />
    <div v-else>Post not found</div>
    <div class="py-4"></div>
</template>
