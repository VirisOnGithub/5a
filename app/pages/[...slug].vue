<script setup lang="ts">
const route = useRoute();
const { data: post } = await useAsyncData(route.path, () =>
    queryCollection("fifthyear").path(route.path).first(),
);

useSeoMeta({
    title: () => post.value?.title,
    description: () => post.value?.description,
    ...post.value?.seo,
});
</script>

<template>
    <UButton
        v-if="post?.path"
        :to="getParentPath(post?.path)"
        class="p-2 m-2 border border-white bg-transparent text-white"
    >
        &larr; Précédent
    </UButton>
    <!-- <pre><code>{{post}}</code></pre> -->
    <div class="py-4"></div>
    <ContentRenderer v-if="post" :value="post" />
    <div v-else>Post not found</div>
    <div class="py-4"></div>
</template>
