<script setup>
const route = useRoute();
const navigation = await useAsyncClassData(true);
const folderNav = navigation.value.filter((e) => e.path === route.path);
const folder = folderNav.length === 1 ? folderNav[0] : undefined;
</script>

<template>
    <UButton
        to="/"
        class="p-2 m-2 border border-white bg-transparent text-white"
    >
        &larr; Retour à l'accueil
    </UButton>
    <h1 class="text-3xl font-bold m-2">{{ folder.title }}</h1>
    <div class="grid grid-cols-3 gap-3">
        <FolderCard :item="item" v-for="item in folder.children" />
    </div>

    <pre><code>{{ folder }}</code></pre>
</template>
